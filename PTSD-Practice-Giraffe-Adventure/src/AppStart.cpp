#include "App.hpp"

#include "Util/Logger.hpp"

void App::Start() {
    glDisable(GL_DEBUG_OUTPUT);
    LOG_TRACE("Start");

    m_Giraffe = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/giraffe.png");
    m_Giraffe->SetPosition({-112.5f, -140.5f});
    m_Giraffe->SetZIndex(50);
    m_Root.AddChild(m_Giraffe);


    m_Chest = std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/chest.png");
    m_Chest->SetZIndex(5);
    m_Chest->SetPosition({197.5f, -3.5f});
    m_Chest->SetVisible(false);
    m_Root.AddChild(m_Chest);

    m_ChestPosition = {197.5f, -3.5f};
    m_ChestWidth = 50.0f;  // 根据你的设计来设定宽度
    m_ChestHeight = 50.0f; // 根据你的设计来设定高度
    m_ChestVisible = true;

    m_GiraffeWidth = 40.0f;
    m_GiraffeHeight = 60.0f;

    std::vector<std::string> beeImages;
    beeImages.reserve(2);
    for (int i = 0; i < 2; ++i) {
        beeImages.emplace_back(GA_RESOURCE_DIR"/Image/Character/bee_" + std::to_string(i + 1) + ".png");
    }

    m_Bee = std::make_shared<AnimatedCharacter>(beeImages,true,true);
    m_Bee->SetZIndex(5);
    m_Bee->SetVisible(false);
    m_Root.AddChild(m_Bee);

    for (int i = 0; i < 3; ++i) {
        m_Doors.push_back(std::make_shared<Character>(GA_RESOURCE_DIR"/Image/Character/door_close.png"));
        m_Doors[i]->SetZIndex(5);
        m_Doors[i]->SetPosition({205.5f - 80.f * i, -3.5f});
        m_Doors[i]->SetVisible(false);
        m_Root.AddChild(m_Doors[i]);
    }

    // TODO: The counting down ball for phase 6
    // 在 AppStart 中創建球的圖片序列
    ballFrames = {
        GA_RESOURCE_DIR"/Image/Character/ball-3.png",
        GA_RESOURCE_DIR"/Image/Character/ball-2.png",
        GA_RESOURCE_DIR"/Image/Character/ball-1.png",
        GA_RESOURCE_DIR"/Image/Character/ball-ok.png"
    };












    m_PRM = std::make_shared<PhaseResourceManger>();
    m_Root.AddChildren(m_PRM->GetChildren());


    m_CurrentState = State::UPDATE;
}

