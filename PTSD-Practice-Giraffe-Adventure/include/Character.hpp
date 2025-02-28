#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "Util/GameObject.hpp"

class Character : public Util::GameObject {
public:

    explicit Character(const std::string& ImagePath);

    Character(const Character&) = delete;

    Character(Character&&) = delete;

    Character& operator=(const Character&) = delete;

    Character& operator=(Character&&) = delete;

    [[nodiscard]] const std::string& GetImagePath() const { return m_ImagePath; }

    [[nodiscard]] const glm::vec2& GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] bool GetVisibility() const { return m_Visible; }

    void SetImage(const std::string& ImagePath);

    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }

    // TODO: Implement the collision detection
    // 构造函数、析构函数（如果需要可以添加）
    Character(float width, float height);

    // 声明碰撞检测函数
    [[nodiscard]] bool IfCollides(const std::shared_ptr<Character>& other) const;

    // 成员变量
    float m_GiraffeWidth;
    float m_GiraffeHeight;

    // 设置可见性
    void SetVisible(bool visible);
    // 获取可见性
    bool IsVisible() const;

    // TODO: Add and implement more methods and properties as needed to finish Giraffe Adventure.

private:
    void ResetPosition() { m_Transform.translation = {0, 0}; }

    std::string m_ImagePath;


};


#endif //CHARACTER_HPP
