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
		// ２次元ベクトル
		static DirectX::XMFLOAT2 float2(float x, float y) {
			return DirectX::XMFLOAT2::XMFLOAT2(x, y);
		}
		static DirectX::XMFLOAT2 float2(float val) {
			return DirectX::XMFLOAT2::XMFLOAT2(val, val);
		}
		// ３次ベクトル
		static DirectX::XMFLOAT3 float3(float x, float y, float z) {
			return DirectX::XMFLOAT3::XMFLOAT3(x, y, z);
		}
		static DirectX::XMFLOAT3 float3(float val) {
			return DirectX::XMFLOAT3::XMFLOAT3(val, val, val);
		}
		// ４次ベクトル
		static DirectX::XMFLOAT4 float4(float x, float y, float z, float w) {
			return DirectX::XMFLOAT4::XMFLOAT4(x, y, z, w);
		}
		static DirectX::XMFLOAT4 float4(float val) {
			return DirectX::XMFLOAT4::XMFLOAT4(val, val, val, 1.0f);
		}
		// 3行3列
		static DirectX::XMFLOAT3X3 matrix3x3(
			float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22) {
			return
				DirectX::XMFLOAT3X3::XMFLOAT3X3(
				m00, m01, m02,
				m10, m11, m12,
				m20, m21, m22);
		}
		static DirectX::XMFLOAT3X3 matrix3x3(const float* arr) {
			return DirectX::XMFLOAT3X3::XMFLOAT3X3(arr);
		}
		// 3行4列
		static DirectX::XMFLOAT3X4 matrix3x4(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23) {
			return
				DirectX::XMFLOAT3X4::XMFLOAT3X4(
				m00, m01, m02, m03,
				m10, m11, m12, m13,
				m20, m21, m22, m23
				);
		}
		static DirectX::XMFLOAT3X4 matrix3x4(const float* arr) {
			return DirectX::XMFLOAT3X4::XMFLOAT3X4(arr);
		}
		// 4行4列
		static DirectX::XMFLOAT4X4 matrix4x4(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33) {
			return
				DirectX::XMFLOAT4X4::XMFLOAT4X4(
			m00, m01, m02, m03,
			m10, m11, m12, m13,
			m20, m21, m22, m23,
			m30, m31, m32, m33);
		}
		static DirectX::XMFLOAT4X4 matrix4x4(const float* arr) {
			return DirectX::XMFLOAT4X4::XMFLOAT4X4(arr);
		}
		// 4行3列
		static DirectX::XMFLOAT4X3 matrix4x3(
			float m00, float m01, float m02,
			float m10, float m11, float m12,
			float m20, float m21, float m22,
			float m30, float m31, float m32) {
			return
				DirectX::XMFLOAT4X3::XMFLOAT4X3(
					m00, m01, m02,
					m10, m11, m12,
					m20, m21, m22,
					m30, m31, m32);
		}
		static DirectX::XMFLOAT4X3 matrix4x3(const float* arr) {
			return DirectX::XMFLOAT4X3::XMFLOAT4X3(arr);
		}
	};
}
