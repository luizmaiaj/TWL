#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{
	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/thomas.png"));

	m_JumpDuration = .45f;
}

// A virtual function
bool Thomas::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;
	}

	m_LeftPressed = Keyboard::isKeyPressed(Keyboard::Q);

	m_RightPressed = Keyboard::isKeyPressed(Keyboard::D);

	return m_JustJumped;
}