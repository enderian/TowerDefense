#ifndef TOWER_H
#define TOWER_H

#define TOWER_SCALE 0.4f
#define TOWER_SHOOT_DISTANCE 10

#include "GeometryNode.h"
#include "Renderer.h"
#include "Game.h"

class OBJLoader;

class Tower : public GameObject
{
	
protected:
	float ready;
	bool m_used = false;

	class GeometryNode* m_tower;
	glm::mat4 m_transformation_matrix;
	glm::mat4 m_transformation_matrix_normal;

public:
	Tower(float ready);
	virtual ~Tower();

	static bool initialize_meshes(OBJLoader& loader);

	bool used() const
	{
		return m_used;
	}

	void set_used(bool used)
	{
		m_used = used;
	}

	void set_position(const glm::vec3& highp_vec3) override;
	void update(Game* game) override;

	glm::vec3 shoot_from();

	void draw_geometry(class Renderer* renderer) override;
	void draw_geometry_to_shadow_map(class Renderer* renderer) override;
};

#endif