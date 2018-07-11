#pragma once

#include "ISelectable.hpp"
#include "IDrawable.hpp"
#include "ITransformable.hpp"
#include "componenttype.h"
#include <QString>

class QPainter;
class Group;
class ActiveSelection;

class VisualEntity : public IDrawable, public ISelectable, public ITransformable
{
public:
    VisualEntity();
    virtual ~VisualEntity();

    void setSelected(bool val) override;
    void toogleSelect() override;
    bool isSelected() override;

    void setParentGroup(Group *val);
    Group* getParentGroup();
    void selfDestruct();

    int getIndex() const;
    QString getName() const; //获取实体名字
    void setIndex(int value);
    void setName(const QString &name);//设置实体名字

    // author: rdd - start -
    int getCompoentId() const;
    void setComponetId(int id);
    int getCompoentType() const;
    void setComponetType(int type);
    // - end-

protected:
    Group *m_parentGroup;
    ActiveSelection *m_selection;

    int m_index;
    QString m_name;

    // author: rdd - start -
    // 用以区别各个组件、方便发请求
    int componentId = -1;
    int compoenntType = ComponentType::None;
    // author: rdd - end -
};

