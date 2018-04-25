#ifndef XTHREE_EXTRUDE_GEOMETRY_HPP
#define XTHREE_EXTRUDE_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // extrude_geometry declaration
    //

    template<class D>
    class xextrude_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xextrude_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using extrude_geometry = xw::xmaterialize<xextrude_geometry>;

    using extrude_geometry_generator = xw::xgenerator<xextrude_geometry>;

    //
    // extrude_geometry implementation
    //

    template <class D>
    inline void xextrude_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xextrude_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xextrude_geometry<D>::xextrude_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xextrude_geometry<D>::set_defaults()
    {
        this->_model_name() = "ExtrudeGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xextrude_geometry));
//}
#endif