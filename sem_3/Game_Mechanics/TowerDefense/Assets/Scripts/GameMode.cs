using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameMode : MonoBehaviour
{
    public bool _isLooping;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    IEnumerator GameLoop()
    {
        while(_isLooping)
        {
            //spawn enemies

            //spawn towers

            //move enemies

            //tick towers

            //apply effects (like poison)

            //damage enemies

            //remove enemies

            //remove towers

            yield return null;
        }
    }
}
