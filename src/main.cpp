#include <Windows.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include "main.h"
#include "rendering/rendering.h"

int main(int argc, char const *argv[])
{
    if (!glfwInit())
    {
        printf("Idiot!\n");
        return 1;
    }



    GLFWwindow* window = glfwCreateWindow(1000, 1000, "Idiot!", nullptr, nullptr);

    Mesh mesh;
    glfwShowWindow(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        RenderMesh(&mesh);
    }

    glfwTerminate();
    printf("Donezo Idiot!\n");
    return 0;
}
