#ifndef XTHREE_GROUP_HPP
#define XTHREE_GROUP_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // group declaration
    //

    template<class D>
    class xgroup : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, type, "Group");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xgroup();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using group = xw::xmaterialize<xgroup>;

    using group_generator = xw::xgenerator<xgroup>;

    //
    // group implementation
    //


    template <class D>
    inline void xgroup<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xgroup<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xgroup<D>::xgroup()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xgroup<D>::set_defaults()
    {
        this->_model_name() = "GroupModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xgroup>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xgroup>;
        extern template xw::xmaterialize<xthree::xgroup>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xgroup>>;
        extern template class xw::xgenerator<xthree::xgroup>;
        extern template xw::xgenerator<xthree::xgroup>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xgroup>>;
    #endif
#endif

#endif