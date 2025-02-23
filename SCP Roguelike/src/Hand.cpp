#include "Hand.hpp"

#include "Util/Input.hpp"
#include "Util/Transform.hpp"
#include "Util/Logger.hpp"

Hand::Hand(std::shared_ptr<Player> player)
    : m_Player(player), m_Animation(std::make_shared<Util::Animation>(
        std::vector<std::string>{
    "C:/Users/lougan/Desktop/SCP Roguelike/Resources/Player/hand.png",
},
true, 50, true, 1000)) {
    m_Transform.translation = { 0, 0 };
    SetDrawable(m_Animation);
}
void Hand::Start() {
    m_Animation->Play();
    m_Transform.scale = { 3,3 };
}
void Hand::Update(){
    m_Transform.translation = m_Player->GetTransform().translation;
}
