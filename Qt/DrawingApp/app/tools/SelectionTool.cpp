#include "SelectionTool.hpp"
#include "ActiveSelection.hpp"
#include "Group.hpp"
#include "Canvas.hpp"
#include "GlobalDrawProperties.hpp"
#include "MoveSelectionCommand.hpp"

#include <QMouseEvent>
#include <QDebug>
#include <QColor>

SelectionTool::SelectionTool(Canvas *canvas) :
    Tool(canvas),
    m_movComm(nullptr), m_clicked(nullptr),
    m_isMousePressed(false), m_hasMoved(false)
{
    m_selection = &ActiveSelection::getInstance();
    m_gp = &GlobalDrawProperties::getInstance();
}

SelectionTool::~SelectionTool()
{

}

void SelectionTool::mousePress(QMouseEvent *event)
{
    m_isMousePressed = true;
    m_mousePressedLoc = event->pos();

    VisualEntity *clicked =
            m_canvas->getVEFromPosition(event->pos().x(), event->pos().y());

    if (clicked != nullptr
            && m_selection->getSize() <= 1
            && !(event->modifiers() & Qt::ShiftModifier)) {
                m_selection->deselectAll();
                clicked->setSelected(true);
                qDebug()<<clicked->getName();
    }

    if (m_selection->getSize() > 0
            && m_selection->contains(event->pos().x(), event->pos().y())) {
        m_movComm = new MoveSelectionCommand(m_mousePressedLoc);
    }
}

void SelectionTool::mouseMove(QMouseEvent *event)
{
    if (m_isMousePressed
            && m_movComm) {
        m_movComm->setPosition(event->pos());
        m_movComm->execute();
        m_hasMoved = true;
    }
}

void SelectionTool::mouseRelease(QMouseEvent *event)
{
    // 应该是根据当前所鼠标释放时的全局位置，通过计算来获得所点击的对象的VE | comment by rdd
    VisualEntity *clicked =
            m_canvas->getVEFromPosition(event->pos().x(), event->pos().y());

    if (clicked != nullptr) {
        // 如果在某个对象上 | comment by rdd
        if (!m_hasMoved) {
            // 如果真个鼠标事件期间没有移动过对象 | comment by rdd
            if ((event->modifiers() & Qt::ShiftModifier)) {
                clicked->toogleSelect();
            } else {
                m_selection->deselectAll();
                clicked->setSelected(true);
            }
        }
    } else {
        // 如果不在某个对象上 | commeny by rdd
        m_selection->deselectAll();
        m_gp->unlinkProperties();
    }

    if (m_hasMoved) {
        // 动过 | comment by rdd
        // 添加到命令栈，应该是用于撤销功能 | commeny by rdd
        m_movComm->addtoCommandStack();
        m_movComm = nullptr;
        m_hasMoved = false;

        // 更新房间组件的位置
        if(clicked->getCompoentType() == ComponentType::Room)
            globalNetBoy->updateRoomPos(clicked->getCompoentId(), clicked->getPosition().x(), clicked->getPosition().y());

    } else if (m_movComm) {
        delete m_movComm;
        m_movComm = nullptr;
    }

    m_isMousePressed = false;
}

