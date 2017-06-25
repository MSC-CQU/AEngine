#include "ColorBuffer.h"
using namespace RenderCore;
using namespace Resource;

namespace RenderCore
{
	namespace Resource
	{
		ColorBuffer::ColorBuffer(Color clearColor) :
			m_clearColor(clearColor), m_numMipMaps(0), m_fragmentCount(1), m_sampleCount(1)
		{
			m_rtvHandle.ptr = GpuVirtualAddressUnknown;
			m_srvHandle.ptr = GpuVirtualAddressUnknown;
			memset(m_uavHandle, 0xff, sizeof(m_uavHandle));
		}

		void ColorBuffer::CreateFromSwapChain(const wstring& name, ID3D12Resource* baseResource,
			ID3D12Device* device)
		{
			// ����Դ���й�����״̬��present�����֣���
			AssociateWithResource(device, name, baseResource, D3D12_RESOURCE_STATE_PRESENT);
			//m_rtvHandle=Al
		}

		D3D12_RESOURCE_FLAGS ColorBuffer::CombineResourceFlags() const
		{
			return D3D12_RESOURCE_FLAGS();
		}

		uint32_t ColorBuffer::ComputeNumMips(uint32_t width, uint32_t height)
		{
			return uint32_t();
		}

		void ColorBuffer::CreateDerivedViews(ID3D12Device * device, DXGI_FORMAT & format, uint32_t arraySize, uint32_t numMips)
		{
		}

		void ColorBuffer::Create(const wstring & name, uint32_t _width, uint32_t _height, uint32_t numMips, DXGI_FORMAT & format, D3D12_GPU_VIRTUAL_ADDRESS vidMemPtr)
		{
		}

		void ColorBuffer::CreateArray(const wstring & name, uint32_t _width, uint32_t _height, uint32_t arrayCount, DXGI_FORMAT & format, D3D12_GPU_VIRTUAL_ADDRESS vidMemPtr)
		{
		}

		const D3D12_CPU_DESCRIPTOR_HANDLE & ColorBuffer::GetSRV() const
		{
			return m_srvHandle;
		}

		const D3D12_CPU_DESCRIPTOR_HANDLE & ColorBuffer::GetRTV() const
		{
			return m_rtvHandle;
		}

		const D3D12_CPU_DESCRIPTOR_HANDLE & ColorBuffer::GetUAV() const
		{
			return m_uavHandle[0];
		}

		void ColorBuffer::SetClearColor(Color clearColor)
		{
		}

		void ColorBuffer::SetMsaaMode(uint32_t numColorSample, uint32_t numCoverageSample)
		{
		}

		Color ColorBuffer::GetClearColor() const
		{
			return Color();
		}
	}
}