#include "pch.h"
#include "ExplosionManager.h"
#include "Sprite.h"

ExplosionManager::ExplosionManager( )
	: m_pExplosions{ }
{
}

ExplosionManager::~ExplosionManager( )
{
	for (Explosion* explosion : m_pExplosions)
	{
		if (explosion != nullptr)
		{
			delete explosion;
		}
	}

	m_pExplosions.clear( );
}

void ExplosionManager::Update(float elapsedSec)
{
	for (int index{}; index < m_pExplosions.size( ); ++index)
	{
		if ( m_pExplosions[index]->GetSprite( )->GetFrameNr( ) == m_pExplosions[index]->GetSprite( )->GetAmountOfFrames( ) - 1 )
		{
			DeleteExplosion(index);
		}
	}

	for (Explosion* explosion : m_pExplosions)
	{
		explosion->Update(elapsedSec);
	}
}

void ExplosionManager::Draw( ) const
{
	for (Explosion* explosion : m_pExplosions)
	{
		explosion->Draw( );
	}
}

void ExplosionManager::AddExplosion(const Point2f& bottomLeftPos, float scale, Explosion::ExplosionType explosionType)
{
	m_pExplosions.push_back(new Explosion{ bottomLeftPos, scale, explosionType });
}

void ExplosionManager::DeleteExplosion(int index)
{
	if (m_pExplosions[index] != nullptr)
	{
		delete m_pExplosions[index];

		m_pExplosions[index] = m_pExplosions.back( );
		m_pExplosions.pop_back( );
	}
}