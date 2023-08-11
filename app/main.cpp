#include <memory>
#include "ApplicationBase.hpp"
#include <imgui.h>

#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>

glm::vec4 DefaultColour = glm::vec4(0.3, 0.7, 0.4, 1.0);

class BasicApp : public gfxlib::ApplicationBase {
public:
    explicit BasicApp(gfxlib::WindowSettings settings) : gfxlib::ApplicationBase(settings) {}

    void OnUpdate(float ts) override
    {
        glClearColor(DefaultColour.r, DefaultColour.g, DefaultColour.b, DefaultColour.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OnUiRender() override
    {
        ImGui::Begin("Hardware Info");
        ImGui::Text("Vendor: %s", m_context.info().vendor.c_str());
        ImGui::Text("Renderer: %s", m_context.info().renderer.c_str());
        ImGui::Text("Version: %s", m_context.info().version.c_str());
        ImGui::End();
    }

    void OnWindowResize(const WindowResizeEvent& event) override {
        std::cout << "Window resize called: " << event.width << " x " << event.height << std::endl;
    }

    void OnKeyPressed(const KeyPressedEvent& event) override {
        std::cout << "Key pressed..." << event.key << std::endl;
    }

    std::string getInfo() {
        auto ctxInfo = m_context.info();
        std::stringstream ss;
        ss << "Vendor: " << ctxInfo.vendor << std::endl << "Renderer: " << ctxInfo.renderer << std::endl << "Version: " << ctxInfo.version << std::endl;
        return ss.str();
    }
};

int main()
{
    gfxlib::WindowSettings settings;
    settings.width = 800;
    settings.height = 600;
    settings.title = "OpenGL Basic App";

    auto myApp = BasicApp(settings);
    myApp.start();

    return 0;
}