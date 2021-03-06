#include "xthreejs/materials/xraw_shader_material_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xraw_shader_material>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xraw_shader_material>;
    template xw::xmaterialize<xthree::xraw_shader_material>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xraw_shader_material>>;
    template class xw::xgenerator<xthree::xraw_shader_material>;
    template xw::xgenerator<xthree::xraw_shader_material>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xraw_shader_material>>;
#endif
