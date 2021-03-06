#include "ShaderClass.h"

RenderCore::Shader::Shader()
{
#if defined _DEBUG || defined DEBUG
	m_compileFlag = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
	m_compileFlag = 0;
#endif // _DEBUG || DEBUG
}

D3D12_SHADER_BYTECODE RenderCore::Shader::GetByteCode()
{
	return CD3DX12_SHADER_BYTECODE(m_blob.Get());
}

void RenderCore::VertexShader::CompileFromFile(string& fileName)
{
	ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(ToLPCWSTR(fileName)).c_str(), nullptr, nullptr, "VSMain", "vs_5_0", m_compileFlag, 0, &m_blob, nullptr));
}

void RenderCore::PixelShader::CompileFromFile(string& fileName)
{
	ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(ToLPCWSTR(fileName)).c_str(), nullptr, nullptr, "PSMain", "ps_5_0", m_compileFlag, 0, &m_blob, nullptr));
}

void RenderCore::GeometryShader::CompileFromFile(string& fileName)
{
	ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(ToLPCWSTR(fileName)).c_str(), nullptr, nullptr, "GSMain", "gs_5_0", m_compileFlag, 0, &m_blob, nullptr));
}

void RenderCore::ComputeShader::CompileFromFile(string& fileName)
{
	ThrowIfFailed(D3DCompileFromFile(GetAssetFullPath(ToLPCWSTR(fileName)).c_str(), nullptr, nullptr, "CSMain", "cs_5_0", m_compileFlag, 0, &m_blob, nullptr));
}
