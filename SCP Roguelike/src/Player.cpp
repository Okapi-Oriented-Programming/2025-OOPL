#include "Player.hpp"

#include "Util/Input.hpp"
#include "Util/Transform.hpp"
#include "Util/Logger.hpp"

Player::Player()
    : m_Animation(std::make_shared<Util::Animation>(
        std::vector<std::string>{
    "C:/Users/lougan/Desktop/SCP Roguelike/Resources/Player/boy.png",
},
true, 50, true, 1000)) {
    m_Transform.translation = { 0, 0 };
    SetDrawable(m_Animation);
}
void Player::Start() {
    m_Animation->Play();
    m_Transform.scale = { 3,3 };
}
void Player::Update() {
    //Move
    float speed = 5;
    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        m_Transform.translation = m_Transform.translation + glm::vec2(0, speed);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        m_Transform.translation = m_Transform.translation + glm::vec2(-speed, 0);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::S)) {
        m_Transform.translation = m_Transform.translation + glm::vec2(0, -speed);
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        m_Transform.translation = m_Transform.translation + glm::vec2(speed, 0);
    }

}
