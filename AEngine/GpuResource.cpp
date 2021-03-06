#include "GpuResource.h"

namespace RenderCore
{
	namespace Resource
	{
		GpuResource::GpuResource() :
			m_gpuVirtualAddress(RenderCore::Resource::GpuVirtualAddressNull),
			m_p_userAllocatedMemory(nullptr),
			m_usageState(D3D12_RESOURCE_STATE_COMMON),
			m_transitioningState((D3D12_RESOURCE_STATES)-1)
		{
		}

		GpuResource::GpuResource(ID3D12Resource * resource, D3D12_RESOURCE_STATES currentState):
			m_gpuVirtualAddress(Resource::GpuVirtualAddressNull),
			m_p_userAllocatedMemory(nullptr),
			m_cp_resource(resource),
			m_usageState(currentState),
			m_transitioningState(static_cast<D3D12_RESOURCE_STATES>(-1))
		{
		}

		void GpuResource::Release()
		{

			m_cp_resource = nullptr;
			m_gpuVirtualAddress = RenderCore::Resource::GpuVirtualAddressNull;
			if (m_p_userAllocatedMemory != nullptr)
			{
				VirtualFree(m_p_userAllocatedMemory, 0, MEM_RELEASE);
				m_p_userAllocatedMemory = nullptr;
			}
		}

		ID3D12Resource * GpuResource::operator->()
		{
			return m_cp_resource.Get();
		}

		const ID3D12Resource * GpuResource::operator->() const
		{
			return m_cp_resource.Get();
		}

		ID3D12Resource * GpuResource::GetResource()
		{
			return m_cp_resource.Get();
		}

		const ID3D12Resource * GpuResource::GetResource() const
		{
			return m_cp_resource.Get();
		}

		D3D12_GPU_VIRTUAL_ADDRESS GpuResource::GetGpuVirtualAddress() const
		{
			return m_gpuVirtualAddress;
		}
	}
}