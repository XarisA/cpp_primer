Output from copy-and-swap version

```
call constructor                                                                                                                                 
call constructor                                                                                                                                 
call constructor                                                                                                                                 
call copy constructor                                                                                                                            
call swap                                                                                                                                        
call destructor                                                                                                                                  
call move constructor                                                                                                                            
call swap                                                                                                                                        
call destructor                                                                                                                                  
call destructor                                                                                                                                  
call destructor   
```

Output from move-assignment version

```
call constructor                                                                                                                                 
call constructor                                                                                                                                 
call constructor                                                                                                                                 
call copy-assignment operator                                                                                                                    
call move-assignment operator                                                                                                                    
call destructor                                                                                                                                  
call destructor  
```