#include "GlobalDrawProperties.hpp"
#include "VisualEntity.hpp"
#include "Group.hpp"
#include "ActiveSelection.hpp"
#include "componenttype.h"

#include <exception>
#include <stdexcept>
#include <QPainter>

VisualEntity::VisualEntity() :
    m_parentGroup(nullptr)
{
    m_selection = &ActiveSelection::getInstance();

    m_index = -1;

    netboy =new NetBoy();
}

VisualEntity::~VisualEntity()
{
    setSelected(false);
}

void VisualEntity::setSelected(bool val)
{
    if (val) {
        m_selection->add(this);
    } else {
        m_selection->remove(this);
    }
}

void VisualEntity::toogleSelect()
{
    m_selection->toggleSelect(this);
}

bool VisualEntity::isSelected()
{
    return m_selection->isSelected(this);
}

void VisualEntity::setParentGroup(Group *val)
{
    m_parentGroup = val;
}

Group *VisualEntity::getParentGroup()
{
    return m_parentGroup;
}

void VisualEntity::selfDestruct()
{
    if (m_parentGroup == nullptr) {
        throw std::runtime_error("Self-destruct only works if Visual Entity is under a parent group!");
    }

    m_parentGroup->destroy(m_index);
}

int VisualEntity::getIndex() const
{
    return m_index;
}

void VisualEntity::setIndex(int value)
{
    m_index = value;
}

QString VisualEntity::getName() const{ //获取实体名字
    return m_name;
}
void VisualEntity::setName(const QString &name){//设置实体名字

    m_name = name;
    if(getCompoentType()==ComponentType::Room){
        //char *ch;
        QByteArray ba = m_name.toLocal8Bit();
        const char *ch = ba.data();
        netboy->changeRoomName(getCompoentId(),ch);
    }
}

// authur: rdd - start -
int VisualEntity::getCompoentId() const
{
    return componentId;
}

void VisualEntity::setComponetId(int id)
{
    componentId = id;
}

int VisualEntity::getCompoentType() const
{
    return compoenntType;
}

void VisualEntity::setComponetType(int type)
{
    compoenntType = type;
};

// authur: rdd - end -
