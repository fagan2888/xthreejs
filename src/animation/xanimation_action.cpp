#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xanimation_action>;
template xw::xmaterialize<xthree::xanimation_action>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xanimation_action>>;
template class xw::xgenerator<xthree::xanimation_action>;
template xw::xgenerator<xthree::xanimation_action>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xanimation_action>>;