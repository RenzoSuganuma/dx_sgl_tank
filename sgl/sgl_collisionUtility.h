#pragma once
#include "vector"
#include "math.h"
#include "limits.h"
#include "DirectXMath.h"
#include "tnl_vector3.h"
#include "sgl_component.h"
#include "DirectXCollision.h" // DirectX::BoundingSphere , DirectX::BoundingOrientedBox
namespace sgl {
	class Overlaps {
	public:
		// ２円または球の当たり判定
		static const bool CheckSphereOverlap(tnl::Vector3& pos1, tnl::Vector3& pos2, float r1, float r2) {
			float center_distance = (pos1 - pos2).length();
			return center_distance <= (r1 + r2);
		}
		// ２円または球の当たり判定
		static const bool CheckSphereOverlapDX(const DirectX::BoundingSphere& a, const DirectX::BoundingSphere& b) {
			return a.Intersects(b);
		}
		// OBBどうしの当たり判定
		static const bool CheckOBBOverlapDX(const DirectX::BoundingOrientedBox& a, const DirectX::BoundingOrientedBox& b) {
			return a.Intersects(b);
		}
		// AABBどうしの当たり判定
		static const bool CheckAABBOverlapDX(const DirectX::BoundingBox& a, const DirectX::BoundingBox& b) {
			return a.Intersects(b);
		}
		// BoundingFrustumどうしの当たり判定
		static const bool CheckFrustumOverlapDX(const DirectX::BoundingFrustum& a, const DirectX::BoundingFrustum& b) {
			return a.Intersects(b);
		}
	};
}
