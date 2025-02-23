#ifndef HAND_HPP
#define HAND_HPP

#include "pch.hpp"

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"
#include "Player.hpp"

class Hand : public Util::GameObject {
public:
    Hand(std::shared_ptr<Player> player);

    void Start();

    void Update();

private:
    std::shared_ptr<Util::Animation> m_Animation;
    std::shared_ptr<Player> m_Player;
};

#endif
