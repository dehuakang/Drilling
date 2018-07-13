#ifndef LAYER_H
#define LAYER_H

#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkDelaunay2D.h>
#include <vtkMath.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkLineSource.h>
#include <QVTKWidget.h>

class Layer
{
public:
    Layer();
    ~Layer();
    vtkSmartPointer<vtkRenderer> renderer;
};


#endif // LAYER_H