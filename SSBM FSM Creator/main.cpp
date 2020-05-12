// SSBM FSM Creator
// main.cpp
// Justyn Durnford
// Created on 5/4/2020
// Last updated on 5/4/2020

#include <GLFW/glfw3.h>

#include <iostream>
using std::cout;
using std::endl;

// This is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) // ESC
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	// Initialize library
	if (!glfwInit())
		return -1;

	GLFWwindow* main_window;

	// Create window and its OpenGL context
	main_window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!main_window)
	{
		glfwTerminate();
		return -1;
	}

	glfwTerminate();
	return 0;
}