// RPGGame
// main.cpp
// Justyn Durnford
// Created on 4/27/2020
// Last updated on 5/20/2020

#include <GLFW/glfw3.h>

#include <iostream>
using std::cout;
using std::endl;

// This is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) // ESC = Close Window
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	// Initialize the library
	if (!glfwInit())
		return -1;

	GLFWwindow* window;

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(640, 480, "Pokemon", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

    // Make the window's context current 
    glfwMakeContextCurrent(window);

    // Set the required callback function
    glfwSetKeyCallback(window, key_callback);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Set the color of the window to gray.
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        // Create the vertecies for the triangle
        glColor3f(1.0f, 0.0f, 0.0f);    // red
        glVertex3f(-1.0f, -1.0f, 0.0f); // left

        glColor3f(0.0f, 1.0f, 0.0f);    // green
        glVertex3f(1.0f, -1.0f, 0.0f);  // right

        glColor3f(0.0f, 0.0f, 1.0f);    // blue
        glVertex3f(0.0f, 1.0f, 0.0f);   // top

        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
	return 0;
}