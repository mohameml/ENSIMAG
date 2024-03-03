import numpy as np

def GD(x0, grad, max_iter, n, L, mu):
    '''
    Parameters
    ----------
    x0: array, shape (nb_features,)
        Initialisation of the solver
    grad: function
        Gradient of the objective function
    max_iter: int
        Number of iterations (i.e. number of descent steps). Note that for GD or SVRG, 
        one iteration is one epoch i.e, one pass through the data, while for SGD, SAG and SAGA, 
        one iteration uses only one data point.
    n: int
        Dataset size
    L: float
        Smoothness constant of the objective function
    mu: float
        Strong convexity constant of the objective function
        
    Returns
    -------
    x: array, shape (nb_features,)
        final iterate of the solver
    x_tab: array, shape (nb_features, max_iter)
        table of all the iterates
    '''
    stepsize  = ######## TODO (2) ########
    x         = x0
    x_tab     = np.copy(x)

    for k in range(max_iter):
        x     = ######## TODO (3): Implement a single step ########
        x_tab = np.vstack((x_tab, x))

    return x, x_tab

def SGD(x0, grad, max_iter, n, L, mu):
    ######## TODO (4) ########

    for k in range(max_iter):
        ######## TODO (4) ########
        
        if k%n == 0: # each completed epoch
            x_tab = np.vstack((x_tab, x))

    return x, x_tab

def SAGA(x0, grad, max_iter, n, L, mu):
    ######## TODO (5) ########

    for k in range(max_iter):
        ######## TODO (5) ########
        
        if k%n == 0: # each completed epoch
            x_tab = np.vstack((x_tab, x))

    return x, x_tab

