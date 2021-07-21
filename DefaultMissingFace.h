#pragma once
#include "MissingFace.h"

enum class MissingFaceForm
{
    Toitsu,
    KanTyan,
    Ryanmen
};

class DefaultMissingFace : public MissingFace<MissingFaceForm>
{

public:
    DefaultMissingFace(MissingFaceForm form, unsigned int num) : MissingFace(form, num)
    {

    }
};

