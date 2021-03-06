#ifndef XTHREE_MATH_HPP
#define XTHREE_MATH_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // math declaration
    //

    template<class D>
    class xmath : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xmath();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using math = xw::xmaterialize<xmath>;

    using math_generator = xw::xgenerator<xmath>;

    //
    // math implementation
    //


    template <class D>
    inline void xmath<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xmath<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xmath<D>::xmath()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmath<D>::set_defaults()
    {
        this->_model_name() = "MathModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmath>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xmath>;
        extern template xw::xmaterialize<xthree::xmath>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xmath>>;
        extern template class xw::xgenerator<xthree::xmath>;
        extern template xw::xgenerator<xthree::xmath>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xmath>>;
    #endif
#endif

#endif