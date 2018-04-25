#ifndef XTHREE_CACHE_HPP
#define XTHREE_CACHE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // cache declaration
    //

    template<class D>
    class xcache : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xcache();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using cache = xw::xmaterialize<xcache>;

    using cache_generator = xw::xgenerator<xcache>;

    //
    // cache implementation
    //

    template <class D>
    inline void xcache<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcache<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcache<D>::xcache()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcache<D>::set_defaults()
    {
        this->_model_name() = "CacheModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xcache));
//}
#endif