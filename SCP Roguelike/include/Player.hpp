#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "pch.hpp"

#include "Util/Animation.hpp"
#include "Util/GameObject.hpp"

class Player : public Util::GameObject {
public:
    Player();

    void Start();

    void Update();

private:
    std::shared_ptr<Util::Animation> m_Animation;
};

#endif
