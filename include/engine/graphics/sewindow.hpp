//
// Created by spounka on 22/06/2020.
//

#ifndef THEDEADWOODS_SRC_WINDOW_HPP_
#define THEDEADWOODS_SRC_WINDOW_HPP_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "camera.hpp"

/** @namespace SE
 *  @brief Namespace holding all the *SEngine* function calls.
 *  
 *  SE - Short for ***SEngine*** - is the root namespace for the function
 *  calls of the GameEngine.
 */

/**
 * @namespace SE::Graphics
 * @brief The namespace holds everything related to GPU and drawing to the screen.
 * 
 * This is where all classes / code related to OpenGL drawing goes
 */

namespace SE::Graphics
{
	//// TODO: add logic for resizing window to the class
	// IMPORTANT: refactor this class
	/**
	 * @brief The class responsible for creating a window object.
	 * The Lib uses GLFW to create a window and stores some useful variables tied together
	 */
	class Window
	{
		/**
		 * @brief A static reference to Camera of the scene
		 */
		static Camera* mainCamera;

		/**
		 * Static method for changing the aspect when the window resize
		 * callback is triggered.
		 * @param window the window to track
		 * @param x the new width of the window 
		 * @param y the new height of the window
		 */
		static void framebuffer_resize_callback(GLFWwindow* window, int x, int y)
		{
			mainCamera->SetProjection(45.0f, (float)x / (float)y);
			glViewport(0, 0, x, y);
		}

	  private:
		/**
		 * @privatesection
		 */

		/**
		 * Stores the width of the current window
		 */

		int m_width,

			/**
		* Stores the height of the current window
		*/
			m_height;

		/**
		 * @brief A reference to GLFWwindow* object
		 */
		GLFWwindow* window;

	  public:
		/** 
		 * Constructor
		 * @param width Initial width of the screen in pixels
		 * @param height Initial height of the screen in pixels
		 * @param title The window title
		 * @param camera reference to Camera of the scene
		 */
		Window(int width, int height, const char* title, Camera* camera);

		/** 
		 * inline Getter for window
		 * @see window
		 * */
		inline GLFWwindow* GetWindow() const
		{
			return this->window;
		}

		/**
		 * @brief The Aspect ratio
		 * @return float the current aspect ratio 
		 */
		inline float GetAspect() const
		{
			return this->m_width / this->m_height;
		}

		/**
		 * Changes the camera's reference
		 * @param cam a pointer to the active camera
		 * @see mainCamera
		 * @see SE::Graphics::Camera
		 */
		static void set_camera(Camera* cam)
		{
			if (mainCamera)
				cam->SetProjection(mainCamera);
			mainCamera = cam;
		}

		/**
		 * @brief Get the current camera object pointer
		 * 
		 * @return SE::Graphics::Camera* the currently selected camera
		 * @see SE::Graphics::Camera
		 */
		static Camera* get_camera()
		{
			return mainCamera;
		}
	};
}// namespace SE::Graphics

#endif//THEDEADWOODS_SRC_WINDOW_HPP_
