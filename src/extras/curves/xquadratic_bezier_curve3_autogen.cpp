#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xquadratic_bezier_curve3>;
template xw::xmaterialize<xthree::xquadratic_bezier_curve3>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xquadratic_bezier_curve3>>;
template class xw::xgenerator<xthree::xquadratic_bezier_curve3>;
template xw::xgenerator<xthree::xquadratic_bezier_curve3>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xquadratic_bezier_curve3>>;