//
// Created by spounka on 22/06/2020.
//

#include "engine/graphics/sewindow.hpp"

#include <iostream>

namespace SE::Graphics
{

	Camera* Window::mainCamera = nullptr;
	
	
	Window::Window(int width, int height, const char* title, Camera* camera) : m_width(width), m_height(height)
	{
		if (!glfwInit())
		{
			std::cerr << "GLFW failed to init!\n";
			exit(255);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		
		window = glfwCreateWindow(width, height, title, nullptr, nullptr);
		glfwMakeContextCurrent(window);

		set_camera(camera);
		glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

		if (glewInit() != GLEW_OK)
		{
			std::cerr << "glew failed to init !\n";
			glfwTerminate();
			exit(255);
		}
	}
}

