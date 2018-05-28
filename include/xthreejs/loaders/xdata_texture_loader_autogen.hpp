#ifndef XTHREE_DATA_TEXTURE_LOADER_HPP
#define XTHREE_DATA_TEXTURE_LOADER_HPP

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
    // data_texture_loader declaration
    //

    template<class D>
    class xdata_texture_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xdata_texture_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using data_texture_loader = xw::xmaterialize<xdata_texture_loader>;

    using data_texture_loader_generator = xw::xgenerator<xdata_texture_loader>;

    //
    // data_texture_loader implementation
    //


    template <class D>
    inline void xdata_texture_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xdata_texture_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xdata_texture_loader<D>::xdata_texture_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdata_texture_loader<D>::set_defaults()
    {
        this->_model_name() = "DataTextureLoaderModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xdata_texture_loader>& widget)
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
        extern template class xw::xmaterialize<xthree::xdata_texture_loader>;
        extern template xw::xmaterialize<xthree::xdata_texture_loader>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xdata_texture_loader>>;
        extern template class xw::xgenerator<xthree::xdata_texture_loader>;
        extern template xw::xgenerator<xthree::xdata_texture_loader>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xdata_texture_loader>>;
    #endif
#endif

#endif