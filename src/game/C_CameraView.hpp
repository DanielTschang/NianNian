#ifndef NIANNIAN_C_CAMERAVIEW_HPP
#define NIANNIAN_C_CAMERAVIEW_HPP

#include "Component.hpp"

class C_CameraView : public Component
{
public:
    C_CameraView(Object* owner);

    void LateUpdate(const float &deltaTime) override;
};



#endif //NIANNIAN_C_CAMERAVIEW_HPP
