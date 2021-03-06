#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::AddRenderObject(std::shared_ptr<RenderObject> aRenderObject)
{
    mRenderObjects.push_back(aRenderObject);
}

void RenderArea::paintEvent(QPaintEvent* /* event */)
{
    for (const auto& renderObject : mRenderObjects)
    {
        renderObject->Render(this);
    }
}
