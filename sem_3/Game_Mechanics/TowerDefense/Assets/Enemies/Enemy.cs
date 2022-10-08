using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    [SerializeField]
    private float _startHealth;
    [SerializeField]
    private float _currentHealth;
    [SerializeField]
    private float _speed;

    public float _id;

    public void Initialize()
    {
        _currentHealth = _startHealth;
    }
}
