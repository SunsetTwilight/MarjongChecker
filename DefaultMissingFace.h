#pragma once
#include "MissingFace.h"

enum class DefaultMissingFaceForm
{
    Toitsu,
    Ryanmen,
    KanTyan,
};

class DefaultMissingFace : public MissingFace<DefaultMissingFaceForm>
{

public:
    DefaultMissingFace(DefaultMissingFaceForm form, unsigned int num) : MissingFace(form, num)
    {

    }
};

