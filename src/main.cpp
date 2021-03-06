/*
 * File: common_types.h
 * Author: Daniel Gaard Hansen
 * Date: 05-12-2020 12:00
 * Description: Entry point.
 */

// System includes
#include <stdio.h>

// Third party
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

// Project
#include "main.h"
#include "rendering/rendering.h"
#include "common_types.h"

GLFWwindow *g_window;

int main(int argc, char const *argv[])
{
    //
    // Initialize!
    //
    if (!glfwInit())
    {
        printf("Failed to initialize GLFW!\n");
        return 1;
    }

    g_window  = glfwCreateWindow(720, 480, "LOADengine!", nullptr, nullptr);
    if(!g_window)
    {
        printf("Failed to create GLFW window!\n");
    }

	
	VkInstance instance;
	VkInstanceCreateInfo createInfo{};
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	if(result != VK_SUCCESS)
	{
		printf("Failed to create Vulkan instance!"
			   "Turns out giving an empty create struct doesn't work!"
			   "Who knew?!\n");
	}
	else
	{
	   printf("... Okay so giving it an empty create struct doesn't crash..."
			  "Probably fail elsewhere, but that is sorta making this bit stupider\n");
	}	

    // @Temporary Can we access stuff in other files? :O
    Mesh mesh;
    
    glfwShowWindow(g_window);

    printf("Running loop!\n");
    while (!glfwWindowShouldClose(g_window))
    {
        glfwPollEvents();
        glfwSwapBuffers(g_window);
        RenderMesh(&mesh);
    }
    printf("Done running loop!\n");
    
    glfwTerminate();
    
    printf("Terminating!\n");
    return 0;
}
