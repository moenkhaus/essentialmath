//===============================================================================
// @ IvShaderProgramD3D9.h
// 
// Description
// ------------------------------------------------------------------------------
// Copyright (C) 2008-2015   James M. Van Verth and Lars M. Bishop.
// All rights reserved.
//
// Change history:
//
// Usage notes
//===============================================================================

#ifndef __IvShaderProgramD3D9__h__
#define __IvShaderProgramD3D9__h__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <map>
#include <string>

#include <d3d11.h>
//#include <D3DX9Shader.h>

#include "../IvShaderProgram.h"
#include "../IvVertexFormats.h"

//-------------------------------------------------------------------------------
//-- Typedefs, Structs ----------------------------------------------------------
//-------------------------------------------------------------------------------

class IvConstantTableD3D11;
class IvResourceManagerD3D11;
class IvUniformD3D11;
class IvVertexShaderD3D11;
class IvFragmentShaderD3D11;

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class IvShaderProgramD3D11 : public IvShaderProgram
{
public:
    // interface routines
    virtual IvUniform* GetUniform(char const* name);

    friend class IvResourceManagerD3D11;
    friend class IvRendererD3D11;
    
private:
    // constructor/destructor
    IvShaderProgramD3D11();
    ~IvShaderProgramD3D11();
    
    // initialization
    bool Create( IvVertexShaderD3D11* vertexShaderPtr, IvFragmentShaderD3D11* fragmentShaderPtr );
    
    // destruction
    void Destroy();
    
    // make this the active program
    bool MakeActive(ID3D11DeviceContext* context);

    // bind the associated uniforms
    bool BindUniforms(ID3D11DeviceContext* context);
    
private:
    // copy operations
    IvShaderProgramD3D11(const IvShaderProgramD3D11& other);
    IvShaderProgramD3D11& operator=(const IvShaderProgramD3D11& other);

private:
    // D3D-specific data
    ID3D11VertexShader*  mVertexShaderPtr;
    IvConstantTableD3D11* mVertexShaderConstants;
    ID3D11PixelShader*   mFragmentShaderPtr;
    IvConstantTableD3D11* mFragmentShaderConstants;

    std::map<std::string, IvUniformD3D11*> mUniforms;
};


//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------

#endif
