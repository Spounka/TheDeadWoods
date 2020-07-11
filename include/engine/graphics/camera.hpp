//
// Created by spounka on 05/06/2020.
//

#ifndef THEDEADWOODS_INCLUDE_CAMERA_HPP_
#define THEDEADWOODS_INCLUDE_CAMERA_HPP_

#include "glm/ext.hpp"
#include "glm/glm.hpp"

#include "engine/vector2.hpp"
#include "engine/vector3.hpp"

namespace SE::Graphics
{
	/**
	 * @brief General Camera Class Of The Engine.
	 */
	class Camera
	{
		// TODO: REMOVE ALL USAGE OF THE GLM LIBRARY
	  private:
		/**
	  	 * @brief The 4x4 Matrix that represents 3D projection
	  	 */
		glm::mat4 m_projection;

		/**
		 * @brief 3D Vector representing the local up axis (y axis)
		 * @see SE::Vector3
		 */
		Vector3 m_up;

		/**
		 * @brief 3D Vector representing the local right axis (x axis)
		 * @see SE::Vector3
		 */
		Vector3 m_right;

		/**
		 * @brief 3D Vector representing the local view front axis (z axis)
		 * @see SE::Vector3
		 */
		Vector3 m_freeviewfront;

		/**
		 * @brief 3D Vector representing the global up axis (y axis)
		 * @see SE::Vector3
		 */
		Vector3 m_worldUp;

		/**
		 * @brief 3D Vector representing the local forward axis ()
		 * @see SE::Vector3
		 */
		Vector3 m_forward;

		/**
		 * @brief 3D Vector representing the position in World space
		 * @see SE::Vector3
		 */
		Vector3 m_position;

		/**
		 * @brief 3D Vector representing the rotation in World space
		 * @see SE::Vector3
		 */
		Vector3 m_rotation;

		/**
		 * @brief used to prevent camera jump when scene first starts
		 */
		bool firstLook = true;

		/**
		 * @brief last frames' mouse X position
		 * 
		 */
		double lastX;

		/**
		 * @brief last frames' mouse Y position
		 * 
		 */
		double lastY;

		/**
		 * @brief Camera's field of view in degrees
		 * 
		 */
		float _fov;

		/**
		 * @brief The current screen aspect ratio
		 * @see SE::Graphics::Window::GetAspect
		 */
		float _aspect;

		/**
		 * @brief The current camera near clipping distance
		 * 
		 */
		float _near;

		/**
		 * @brief The current camera far clipping distance
		 * 
		 */
		float _far;

	  public:
		/**
		 * @brief enum representing camera directions used for moving
		 * @see MoveCameraKeyboard
		 */
		enum CAMERA_DIRECTION
		{
			/**
			 * @brief front direction (note: this is the front as in First person style and not as 
			 * 		free view style).
			 */
			FRONT,

			BACK,///< back direction

			RIGHT,///< right direction

			LEFT,///< left direction

			UP,///< up direction (note: this is along global up and not local up)

			DOWN///< down direction (note: this is along global down and not local down)
		};

		/**
		 * @brief 			Construct a new Camera object
		 * 
		 * @param pos 		The initial position. defaults to (0,0,0)
		 * @param rot 		The initial rotation. defaults to (0,0,0)
		 * @param worldUp 	The world up. defaults to (0,1,0)
		 */
		explicit Camera(Vector3 pos = Vector3(0), Vector3 rot = Vector3(0, 0, 0),
						Vector3 worldUp = Vector3(0, 1, 0));

		/**
		 * @brief returns the projection matrix
		 * 
		 * @return glm::mat4
		 * @see m_projection
		 */
		glm::mat4 GetView();

		/**
		 * @brief			Set the Projection matrix
		 * 
		 * @param fov 		field of view in degrees
		 * @param aspect 	aspect ratio
		 * @param near 		the near plane distance
		 * @param far 		the far plane distance
		 */
		void SetProjection(float fov = glm::radians(45.0f), float aspect = 1.0f, float near = 0.01f,
						   float far = 100);

		/**
		 * @brief copies the Projection matrix from another camera
		 * 
		 * @param Camera* the camera to copy projection from
		 */
		void SetProjection(const Camera* cam);

		/**
		 * @brief Updates the local camera axis (to call whenver rotations change)
		 */
		void UpdateLocalAxis();

		/**
		 * @brief Get the Position vector
		 * 
		 * @return Vector3& 
		 */
		inline Vector3& GetPosition() { return this->m_position; }

		/**
		 * @brief Get the Rotation vector
		 * 
		 * @return Vector3& 
		 */
		inline Vector3& GetRotation() { return this->m_rotation; }

		/**
		 * @brief Get the Free View Front vector
		 * 
		 * @return Vector3& 
		 */
		inline Vector3& GetFreeViewFront() { return this->m_freeviewfront; }

		/**
		 * @brief Get the Front vector
		 * 
		 * @return Vector3& 
		 */
		inline Vector3& GetFront() { return this->m_forward; }

		/**
		 * @brief Get the Up vector
		 * 
		 * @return Vector3 
		 */
		inline Vector3 GetUp() { return this->m_up; }

		/**
		 * @brief Get the Projection matrix
		 * 
		 * @return glm::mat4 
		 */
		inline glm::mat4 GetProjection() { return m_projection; }

		/**
		 * @brief Updates the Camera View from mouse position
		 * 			(note: the positions are swapped and handled internally by the function)
		 * 
		 * @param x mouse x position 
		 * @param y mouse y position
		 */
		void SetCameraView(double x, double y);

		/**
		 * @brief Method used for moving the camera in an abstract / library agnostic way
		 * 
		 * @param direction The direction in which the camera should move
		 * @param speed The speed to move the camera by
		 * @see CAMERA_DIRECTION
		 */
		void MoveCameraKeyboard(CAMERA_DIRECTION direction, float speed);
	};

}// namespace SE::Graphics
#endif//THEDEADWOODS_INCLUDE_CAMERA_HPP_