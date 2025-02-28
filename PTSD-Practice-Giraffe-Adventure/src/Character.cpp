#include "Character.hpp"
#include "Util/Image.hpp"


Character::Character(const std::string& ImagePath) {
    SetImage(ImagePath);

    ResetPosition();
}

// 构造函数实现
Character::Character(float width, float height)
    : m_GiraffeWidth(width), m_GiraffeHeight(height) {
    // 你可以在这里进行初始化操作
}

// IfCollides 函数实现
bool Character::IfCollides(const std::shared_ptr<Character>& other) const {
    float thisWidth = m_GiraffeWidth;
    float thisHeight = m_GiraffeHeight;

    float otherWidth = other->m_GiraffeWidth;
    float otherHeight = other->m_GiraffeHeight;

    // 简单的碰撞检测逻辑，检查两个矩形是否重叠
    return !(thisWidth < otherWidth || thisHeight < otherHeight);
}

void Character::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;

    m_Drawable = std::make_shared<Util::Image>(m_ImagePath);
}

void Character::SetVisible(bool visible) {
    m_Visible = visible;  // 设置可见性
}

bool Character::IsVisible() const {
    return m_Visible;  // 返回当前可见性状态
}
