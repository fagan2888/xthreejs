#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmesh_basic_material>;
template xw::xmaterialize<xthree::xmesh_basic_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmesh_basic_material>>;
template class xw::xgenerator<xthree::xmesh_basic_material>;
template xw::xgenerator<xthree::xmesh_basic_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmesh_basic_material>>;