#ifndef XTHREE_MESH_LAMBERT_MATERIAL_HPP
#define XTHREE_MESH_LAMBERT_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmaterial.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // mesh_lambert_material declaration
    //

    template<class D>
    class xmesh_lambert_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, alphaMap);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, aoMap);
        XPROPERTY(double, derived_type, aoMapIntensity, 1);
        XPROPERTY(xw::html_color, derived_type, color, "#ffffff");
        XPROPERTY(std::string, derived_type, combine, "MultiplyOperation", xenums::Operations);
        XPROPERTY(xw::html_color, derived_type, emissive, "#000000");
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, emissiveMap);
        XPROPERTY(double, derived_type, emissiveIntensity, 1);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, envMap);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, lightMap);
        XPROPERTY(double, derived_type, lightMapIntensity, 1);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, map);
        XPROPERTY(bool, derived_type, morphNormals, false);
        XPROPERTY(bool, derived_type, morphTargets, false);
        XPROPERTY(double, derived_type, reflectivity, 1);
        XPROPERTY(double, derived_type, refractionRatio, 0.98);
        XPROPERTY(bool, derived_type, skinning, false);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, specularMap);
        XPROPERTY(bool, derived_type, wireframe, false);
        XPROPERTY(std::string, derived_type, wireframeLinecap, "round");
        XPROPERTY(std::string, derived_type, wireframeLinejoin, "round");
        XPROPERTY(double, derived_type, wireframeLinewidth, 1);
        XPROPERTY(std::string, derived_type, type, "MeshLambertMaterial");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xmesh_lambert_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using mesh_lambert_material = xw::xmaterialize<xmesh_lambert_material>;

    using mesh_lambert_material_generator = xw::xgenerator<xmesh_lambert_material>;

    //
    // mesh_lambert_material implementation
    //


    template <class D>
    inline void xmesh_lambert_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(alphaMap, state, buffers);
        xw::set_patch_from_property(aoMap, state, buffers);
        xw::set_patch_from_property(aoMapIntensity, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(combine, state, buffers);
        xw::set_patch_from_property(emissive, state, buffers);
        xw::set_patch_from_property(emissiveMap, state, buffers);
        xw::set_patch_from_property(emissiveIntensity, state, buffers);
        xw::set_patch_from_property(envMap, state, buffers);
        xw::set_patch_from_property(lightMap, state, buffers);
        xw::set_patch_from_property(lightMapIntensity, state, buffers);
        xw::set_patch_from_property(map, state, buffers);
        xw::set_patch_from_property(morphNormals, state, buffers);
        xw::set_patch_from_property(morphTargets, state, buffers);
        xw::set_patch_from_property(reflectivity, state, buffers);
        xw::set_patch_from_property(refractionRatio, state, buffers);
        xw::set_patch_from_property(skinning, state, buffers);
        xw::set_patch_from_property(specularMap, state, buffers);
        xw::set_patch_from_property(wireframe, state, buffers);
        xw::set_patch_from_property(wireframeLinecap, state, buffers);
        xw::set_patch_from_property(wireframeLinejoin, state, buffers);
        xw::set_patch_from_property(wireframeLinewidth, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xmesh_lambert_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(alphaMap, patch, buffers);
        xw::set_property_from_patch(aoMap, patch, buffers);
        xw::set_property_from_patch(aoMapIntensity, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(combine, patch, buffers);
        xw::set_property_from_patch(emissive, patch, buffers);
        xw::set_property_from_patch(emissiveMap, patch, buffers);
        xw::set_property_from_patch(emissiveIntensity, patch, buffers);
        xw::set_property_from_patch(envMap, patch, buffers);
        xw::set_property_from_patch(lightMap, patch, buffers);
        xw::set_property_from_patch(lightMapIntensity, patch, buffers);
        xw::set_property_from_patch(map, patch, buffers);
        xw::set_property_from_patch(morphNormals, patch, buffers);
        xw::set_property_from_patch(morphTargets, patch, buffers);
        xw::set_property_from_patch(reflectivity, patch, buffers);
        xw::set_property_from_patch(refractionRatio, patch, buffers);
        xw::set_property_from_patch(skinning, patch, buffers);
        xw::set_property_from_patch(specularMap, patch, buffers);
        xw::set_property_from_patch(wireframe, patch, buffers);
        xw::set_property_from_patch(wireframeLinecap, patch, buffers);
        xw::set_property_from_patch(wireframeLinejoin, patch, buffers);
        xw::set_property_from_patch(wireframeLinewidth, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xmesh_lambert_material<D>::xmesh_lambert_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmesh_lambert_material<D>::set_defaults()
    {
        this->_model_name() = "MeshLambertMaterialModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmesh_lambert_material>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xmesh_lambert_material>;
        extern template xw::xmaterialize<xthree::xmesh_lambert_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xmesh_lambert_material>>;
        extern template class xw::xgenerator<xthree::xmesh_lambert_material>;
        extern template xw::xgenerator<xthree::xmesh_lambert_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xmesh_lambert_material>>;
    #endif
#endif

#endif