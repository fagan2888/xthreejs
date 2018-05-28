#ifndef XTHREE_ANIMATION_OBJECT_GROUP_HPP
#define XTHREE_ANIMATION_OBJECT_GROUP_HPP

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
    // animation_object_group declaration
    //

    template<class D>
    class xanimation_object_group : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xanimation_object_group();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using animation_object_group = xw::xmaterialize<xanimation_object_group>;

    using animation_object_group_generator = xw::xgenerator<xanimation_object_group>;

    //
    // animation_object_group implementation
    //


    template <class D>
    inline void xanimation_object_group<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xanimation_object_group<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xanimation_object_group<D>::xanimation_object_group()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xanimation_object_group<D>::set_defaults()
    {
        this->_model_name() = "AnimationObjectGroupModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xanimation_object_group>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xanimation_object_group>;
        extern template xw::xmaterialize<xthree::xanimation_object_group>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xanimation_object_group>>;
        extern template class xw::xgenerator<xthree::xanimation_object_group>;
        extern template xw::xgenerator<xthree::xanimation_object_group>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xanimation_object_group>>;
    #endif
#endif

#endif