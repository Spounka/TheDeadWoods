//
// Created by spounka on 05/06/2020.
//

#include "engine/graphics/camera.hpp"

#include "glm/glm.hpp"

namespace SE::Graphics
{
	Camera::Camera(Vector3 pos, Vector3 rot, Vector3 worldUp) :
		m_position(pos), m_rotation(rot), m_worldUp(worldUp)
	{
		m_rotation.y = -90;
		UpdateLocalAxis();
	}

	void Camera::UpdateLocalAxis()
	{
		Vector3 front;
		front.x = cos(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x));
		front.y = sin(glm::radians(m_rotation.x));
		front.z = sin(glm::radians(m_rotation.y)) * cos(glm::radians(m_rotation.x));
		m_freeviewfront = front.Normalized();
        m_right = (m_freeviewfront * m_worldUp).Normalized();
		m_up = (m_right * m_freeviewfront).Normalized();
		m_forward = (m_worldUp * m_right).Normalized();
	}
	glm::mat4 Camera::GetView()
	{
		return glm::lookAt(m_position.ToGlm(), (m_freeviewfront + m_position).ToGlm(), m_up.ToGlm());
	}
	void Camera::SetProjection(float fov, float aspect, float near, float far)
	{
		_aspect = aspect;
		_fov = fov;
		_near = near;
		_far = far;
		m_projection = glm::perspective(glm::radians(_fov), _aspect, _near, _far);
	}

	void Camera::SetProjection(const Camera* cam)
	{
		_aspect = cam->_aspect;
		_fov = cam->_fov;
		_near = cam->_near;
		_far = cam->_far;
		m_projection = glm::perspective(glm::radians(_fov), _aspect, _near, _far);
	}

	void Camera::SetCameraView(double x, double y)
	{
		if (firstLook)
		{
			lastX = x;
			lastY = y;
			firstLook = false;
		}
		double differenceX = x - lastX;
		double differenceY = lastY - y;
		m_rotation.x += differenceY * 0.05f;
		m_rotation.y += differenceX * 0.05f;

		if (m_rotation.x > 89)
			m_rotation.x = 89;
		if (m_rotation.x < -89)
			m_rotation.x = -89;
		UpdateLocalAxis();
		lastX = x;
		lastY = y;
	}
	void Camera::MoveCameraKeyboard(Camera::CAMERA_DIRECTION direction, float speed)
	{
		Vector3 dir(0);
		if (direction == FRONT)
			dir += m_forward;
		else if (direction == BACK)
			dir -= m_forward;
		if (direction == RIGHT)
			dir += m_right;
		else if (direction == LEFT)
			dir -= m_right;
		if (direction == UP)
			dir += m_worldUp;
		else if (direction == DOWN)
			dir -= m_worldUp;
		Vector3 velocity = dir.Normalized() * speed;
		m_position += velocity;
		UpdateLocalAxis();
	}
}
