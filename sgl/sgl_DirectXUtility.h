#pragma once
#include "DirectXCollision.h" // DirectX::BoundingSphere , DirectX::BoundingOrientedBox
// DirectX::BoundingBox AABB
using DxAABB = DirectX::BoundingBox;
// DirectX::BoundingOrientedBox OBB
using DxOBB = DirectX::BoundingOrientedBox;
// DirectX::BoundingSphere
using DxBSphere = DirectX::BoundingSphere;
// DirectX::BoundingFrustum
using DxBFrustum = DirectX::BoundingFrustum;
namespace sgl {
	// DirectXのユーティリティクラス
	class DxUtil {
	public:
		// ３次ベクトル
		static DirectX::XMFLOAT3 xm_Float3(float x, float y, float z) {
			return DirectX::XMFLOAT3::XMFLOAT3(x, y, z);
		}
		static DirectX::XMFLOAT3 xm_Float3(float val) {
			return DirectX::XMFLOAT3::XMFLOAT3(val, val, val);
		}
		// ４次ベクトル
		static DirectX::XMFLOAT4 xm_Float4(float x, float y, float z, float w) {
			return DirectX::XMFLOAT4::XMFLOAT4(x, y, z, w);
		}
		static DirectX::XMFLOAT4 xm_Float4(float val) {
			return DirectX::XMFLOAT4::XMFLOAT4(val, val, val, 1.0f);
		}
	};
}
