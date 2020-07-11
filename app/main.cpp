#include <iostream>
#include <vector>

#include <GL/glew.h>

#include "GLFW/glfw3.h"

#include "engine.hpp"
#include "engine/util/Logger/logger.hpp"


void SetUniforms(SE::Graphics::Camera* cam, GLuint prog, const glm::mat4& m);
void ProcessMouseMovement(GLFWwindow*, double x, double y);

SE::Graphics::Camera* camera;
SE::Graphics::Window* window;

double currentTime, lastTime, deltaTime;

int main()
{
	camera = new SE::Graphics::Camera(SE::Vector3(0, 0, 3));
	camera->SetProjection(45.0f, 800.0f / 600.0f);

	window = new SE::Graphics::Window(800, 600, "TheDeadWoods", camera);

	SE::Graphics::Camera secondaryCamera(SE::Vector3(), SE::Vector3(30, 0, 0));
	secondaryCamera.SetProjection(camera);

	glfwSetCursorPosCallback(window->GetWindow(), ProcessMouseMovement);

	const std::string textDir = std::string(RESOURCES) + "/WoodWenge.jpeg";
	const std::string modelDir = std::string(RESOURCES) + "/cube.fbx";

	SE::Graphics::Shader shader;
	SE::Graphics::Texture mainTexture(textDir.c_str());

	SE::Graphics::Material mat(shader);
	SE::Graphics::SunMaterial Sun(shader);
	SE::Graphics::AreaLightMaterial Lamp(shader);
	SE::Graphics::FlashLightMaterial Torch(shader);

	SE::Graphics::Model mod(modelDir, shader);

	glm::mat4 model = glm::mat4(1);
	model = glm::translate(model, SE::Vector3(0, 0, 1).ToGlm());
	lastTime = glfwGetTime();

	glEnable(GL_DEPTH_TEST);

	Sun.SetColor(SE::Vector3(0, 0, 0.3));
	Sun.SetAmbient(SE::Vector3(0.0f, 0.0f, 0.0f));
	Sun.SetDirection(SE::Vector3(1.0f, -1.0f, 1.0f));

	Lamp.SetPosition(SE::Vector3(0, 2, 0));
	Lamp.SetAmbient(SE::Vector3(0.0f, 0.0f, 0.0f));
	Lamp.SetColor(SE::Vector3(0.0, 0.0, 0.01f));
	Lamp.SetCLinear(0.18f);
	Lamp.SetCQuadratic(0.064f);

	Torch.SetPosition(SE::Graphics::Window::get_camera()->GetPosition());
	Torch.SetDirection(SE::Graphics::Window::get_camera()->GetFreeViewFront());
	Torch.SetInnerRing(10.5f);

	Torch.SetColor(SE::Vector3(0.4f));
	Torch.SetAmbient(SE::Vector3(.05f));

	Torch.SetCLinear(0.18f);
	Torch.SetCQuadratic(0.064f);

	mat.SetColor(SE::Vector3(1, 1, 1));
	SE::Util::Logger log(5, LOG_FULLTIME | LOG_USER);

	while (!glfwWindowShouldClose(window->GetWindow()))
	{
		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		
		char fpsLog[50] = { 0};
		sprintf(fpsLog, "time: %fms\tframes: %ffps", deltaTime * 1000, 1 / deltaTime);
		log.LogMessage(fpsLog);
		lastTime = currentTime;
		
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window->GetWindow(), true);
			break;
		}
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_1) == GLFW_PRESS)
			SE::Graphics::Window::set_camera(camera);
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_2) == GLFW_PRESS)
			SE::Graphics::Window::set_camera(&secondaryCamera);

		float speed = (float)deltaTime * 2.5f;
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
		{
			SE::Graphics::Window::get_camera()->MoveCameraKeyboard(SE::Graphics::Camera::FRONT, speed);
		}
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
		{
			SE::Graphics::Window::get_camera()->MoveCameraKeyboard(SE::Graphics::Camera::BACK, speed);
		}
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_E) == GLFW_PRESS)
		{
			SE::Graphics::Window::get_camera()->MoveCameraKeyboard(SE::Graphics::Camera::UP, speed);
		}
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_Q) == GLFW_PRESS)
		{
			SE::Graphics::Window::get_camera()->MoveCameraKeyboard(SE::Graphics::Camera::DOWN, speed);
		}
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
		{
			SE::Graphics::Window::get_camera()->MoveCameraKeyboard(SE::Graphics::Camera::RIGHT, speed);
		}
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
		{
			SE::Graphics::Window::get_camera()->MoveCameraKeyboard(SE::Graphics::Camera::LEFT, speed);
		}

		if (glfwGetKey(window->GetWindow(), GLFW_KEY_R) == GLFW_PRESS)
		{
			SE::Graphics::Window::get_camera()->GetRotation() = SE::Vector3(0, 90, 0);
			SE::Graphics::Window::get_camera()->GetPosition() = SE::Vector3(0, 0, -3);
			SE::Graphics::Window::get_camera()->UpdateLocalAxis();
		}
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_P) == GLFW_PRESS)
			glfwSetInputMode(window->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_UP) == GLFW_PRESS)
			model = glm::translate(model, SE::Vector3(0, 0, 0.3f).ToGlm());
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
			model = glm::translate(model, SE::Vector3(0, 0, -0.3).ToGlm());
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
			model = glm::rotate(model, glm::radians(-5.0f), SE::Vector3(0, 1, 0).ToGlm());
		if (glfwGetKey(window->GetWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
			model = glm::rotate(model, glm::radians(5.0f), SE::Vector3(0, 1, 0).ToGlm());
		glClearColor(.0f, 1.0f, 1.0f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUniform3fv(glGetUniformLocation(shader.GetShader(), "viewPos"),
			1,
			&SE::Graphics::Window::get_camera()->GetPosition().x);

		SetUniforms(SE::Graphics::Window::get_camera(), shader.GetShader(), model);

		
		Torch.SetPosition(SE::Graphics::Window::get_camera()->GetPosition());
		Torch.SetDirection(SE::Graphics::Window::get_camera()->GetFreeViewFront());


		mat.UseMaterial();
		mainTexture.Bind();
		mod.Draw();

		glfwSwapBuffers(window->GetWindow());
		glfwPollEvents();
	}
	glfwSetInputMode(window->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	log.Destroy();
	
	delete camera;
	delete window;

	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void SetUniforms(SE::Graphics::Camera* cam, GLuint prog, const glm::mat4& m)
{
	glUseProgram(prog);
	auto mod = glGetUniformLocation(prog, "model");
	auto vie = glGetUniformLocation(prog, "view");
	auto proj = glGetUniformLocation(prog, "projection");

	glUniformMatrix4fv(mod, 1, GL_FALSE, glm::value_ptr(m));
	glUniformMatrix4fv(vie, 1, GL_FALSE, glm::value_ptr(cam->GetView()));
	glUniformMatrix4fv(proj, 1, GL_FALSE, glm::value_ptr(cam->GetProjection()));
}

void ProcessMouseMovement(GLFWwindow*, double x, double y)
{
	SE::Graphics::Window::get_camera()->SetCameraView(x, y);
}
