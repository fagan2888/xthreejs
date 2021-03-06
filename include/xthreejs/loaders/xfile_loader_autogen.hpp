#ifndef XTHREE_FILE_LOADER_HPP
#define XTHREE_FILE_LOADER_HPP

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
    // file_loader declaration
    //

    template<class D>
    class xfile_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xfile_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using file_loader = xw::xmaterialize<xfile_loader>;

    using file_loader_generator = xw::xgenerator<xfile_loader>;

    //
    // file_loader implementation
    //


    template <class D>
    inline void xfile_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xfile_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xfile_loader<D>::xfile_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xfile_loader<D>::set_defaults()
    {
        this->_model_name() = "FileLoaderModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfile_loader>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xfile_loader>;
        extern template xw::xmaterialize<xthree::xfile_loader>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xfile_loader>>;
        extern template class xw::xgenerator<xthree::xfile_loader>;
        extern template xw::xgenerator<xthree::xfile_loader>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xfile_loader>>;
    #endif
#endif

#endif