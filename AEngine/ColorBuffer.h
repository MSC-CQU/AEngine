#pragma once
#ifndef __COLORBUFFER_H__
#define __COLORBUFFER_H__

#include"DX.h"
#include"PixelBuffer.h"
#include"Color.h"
#include"DescriptorHeap.h"
using namespace std;
using namespace RenderCore;

namespace RenderCore
{
	namespace Resource
	{
		class ColorBuffer : public PixelBuffer
		{
		protected:
			Color m_clearColor;
			D3D12_CPU_DESCRIPTOR_HANDLE m_srvHandle;
			D3D12_CPU_DESCRIPTOR_HANDLE m_rtvHandle;
			D3D12_CPU_DESCRIPTOR_HANDLE m_uavHandle[12];
			uint32_t m_numMipMaps;	//子纹理层数量
			uint32_t m_fragmentCount;
			uint32_t m_sampleCount;

			D3D12_RESOURCE_FLAGS CombineResourceFlags() const;
			static uint32_t ComputeNumMips(uint32_t width, uint32_t height);
			void CreateDerivedViews(ID3D12Device* device, DXGI_FORMAT& format,
				uint32_t arraySize, uint32_t numMips = 1);

		public:
			ColorBuffer();
			~ColorBuffer() = default;
			ColorBuffer(Color clearColor);

			// 从交换链缓冲区创建颜色缓冲区，无序访问受限。
			void CreateFromSwapChain(const wstring& name, ID3D12Resource* baseResource,
				ID3D12Device* device, RenderCore::Heap::DescriptorAllocator* heapDescAllocator);
			// 创建颜色缓冲区，如果提供了地址则不会分配内存。虚拟地址允许重命名缓冲器（对于跨越帧重用ESRAM特别有用）。？？
			void Create(const wstring& name, uint32_t _width, uint32_t _height, uint32_t numMips,
				DXGI_FORMAT& format, D3D12_GPU_VIRTUAL_ADDRESS vidMemPtr = RenderCore::Resource::GpuVirtualAddressUnknown);
			// 创建颜色缓冲区，将内存分配到ESRAM（Xbox One）。在Windows上，这个功能与Create()没有视频地址时相同。 ??
			//void Create(const std::wstring& name, uint32_t _width, uint32_t _height, uint32_t numMips,
			//	DXGI_FORMAT& format, EsramAllocator& allocator);

			// 创建颜色缓冲区，如果提供了地址则不会分配内存。虚拟地址允许重命名缓冲器（对于跨越帧重用ESRAM特别有用）。？？
			void CreateArray(const wstring& name, uint32_t _width, uint32_t _height, uint32_t arrayCount,
				DXGI_FORMAT& format, D3D12_GPU_VIRTUAL_ADDRESS vidMemPtr = RenderCore::Resource::GpuVirtualAddressUnknown);

			// 获取CPU可访问的句柄
			const D3D12_CPU_DESCRIPTOR_HANDLE& GetSRV() const;
			// 获取CPU可访问的句柄
			const D3D12_CPU_DESCRIPTOR_HANDLE& GetRTV() const;
			// 获取CPU可访问的句柄
			const D3D12_CPU_DESCRIPTOR_HANDLE& GetUAV() const;
			void SetClearColor(Color clearColor);
			void SetMsaaMode(uint32_t numColorSample, uint32_t numCoverageSample);
			Color GetClearColor() const;
		};
	}
}

#endif // !__COLORBUFFER_H__
