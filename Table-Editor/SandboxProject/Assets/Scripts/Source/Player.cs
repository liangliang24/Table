using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Table;

namespace Sandbox
{
    public class Player : Entity
    {
        private TransformComponent m_Transform;
        private Rigidbody2DComponent m_Rigidbody;

        public float Speed;
        public float AngularSpeed;
        public float Time = 0.0f;

        void OnCreate()
        {
            Console.WriteLine($"Player.OnCreate - {ID}");

            m_Transform = GetComponent<TransformComponent>();
            m_Rigidbody = GetComponent<Rigidbody2DComponent>();
        }

        void OnUpdate(float ts)
        {
            //Console.WriteLine($"Player.OnUpdate: {ts}");
            Time += ts;
            float speed = Speed;
            float angularSpeed = AngularSpeed;
            Vector3 velocity = Vector3.Zero;

            if (Input.IsKeyDown(KeyCode.W))
                velocity.Y = 1.0f;
            else if (Input.IsKeyDown(KeyCode.S))
                velocity.Y = -1.0f;

            float angulerImpulse = 0;
            if (Input.IsKeyDown (KeyCode.Q))
            {
                angulerImpulse = 0.1f;
            }
            else if (Input.IsKeyDown (KeyCode.E))
            {
                angulerImpulse = -0.1f;
            }
            velocity *= speed * ts;
            angulerImpulse *= ts * angularSpeed;
            if(m_Rigidbody != null) 
            {
                m_Rigidbody.ApplyLinearImpulse(velocity.XY, true);
                m_Rigidbody.ApplyAngulerImpulse(angulerImpulse, true);
            }
            else
            {
                Vector3 translation = m_Transform.Translation;
                translation += velocity * ts;
                m_Transform.Translation = translation;
            }
        }

    }
}