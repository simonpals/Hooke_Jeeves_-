# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>

using namespace std;

# include "hooke.hpp"

double best_nearby ( double delta[], double point[], double prevbest, 
  int nvars, double f ( double x[], int nvars ), int *funevals )
{
  double ftmp;
  int i;
  double minf;
  double *z;

  z = new double[nvars];

  minf = prevbest;

  for ( i = 0; i < nvars; i++ )
  {
   z[i] = point[i];
  }

  for ( i = 0; i < nvars; i++ )
  {
    z[i] = point[i] + delta[i];

    ftmp = f ( z, nvars );
    *funevals = *funevals + 1;

    if ( ftmp < minf )
    {
      minf = ftmp;
    }
    else
    {
      delta[i] = - delta[i];
      z[i] = point[i] + delta[i];
      ftmp = f ( z, nvars );
      *funevals = *funevals + 1;

      if ( ftmp < minf )
      {
        minf = ftmp;
      }
      else
      {
        z[i] = point[i];
      }
    }
  }

  for ( i = 0; i < nvars; i++ )
  {
    point[i] = z[i];
  }

  delete [] z;

  return minf;
}

int hooke ( int nvars, double startpt[], double endpt[], double rho, double eps, 
  int itermax, double f ( double x[], int nvars ) )   
{
  double *delta;
  double fbefore;
  int funevals;
  int i;
  int iters;
  int j;
  int keep;
  double newf;
  double *newx;
  double steplength;
  double tmp;
  bool verbose = false;
  double *xbefore;

  delta = new double[nvars];
  newx = new double[nvars];
  xbefore = new double[nvars];

  for ( i = 0; i < nvars; i++ )
  {
    newx[i] = startpt[i];
  }

  for ( i = 0; i < nvars; i++ )
  {
    xbefore[i] = startpt[i];
  }

  for ( i = 0; i < nvars; i++ )
  {
    if ( startpt[i] == 0.0 )
    {
      delta[i] = rho;
    }
    else
    {
      delta[i] = rho * r8_abs ( startpt[i] );
    }
  }

  funevals = 0;
  steplength = rho;
  iters = 0;
  fbefore = f ( newx, nvars );
  funevals = funevals + 1;
  newf = fbefore;

  while ( iters < itermax && eps < steplength )
  {
    iters = iters + 1;

    if ( verbose )
    {
      cout << "\n";
      cout << "  FUNEVALS, = " << funevals
           << "  F(X) = " << fbefore << "\n";

      for ( i = 0; i < nvars; i++ )
      {
        cout << "  " << i + 1
             << "  " << xbefore[i] << "\n";
      }
    }

    for ( i = 0; i < nvars; i++ )
    {
      newx[i] = xbefore[i];
    }

    newf = best_nearby ( delta, newx, fbefore, nvars, f, &funevals );

    keep = 1;

    while ( newf < fbefore && keep == 1 )
    {
      for ( i = 0; i < nvars; i++ )
      {
        if ( newx[i] <= xbefore[i] )
        {
          delta[i] = - r8_abs ( delta[i] );
        }
        else
        {
          delta[i] = r8_abs ( delta[i] );
        }

        tmp = xbefore[i];
        xbefore[i] = newx[i];
        newx[i] = newx[i] + newx[i] - tmp;
      }

      fbefore = newf;
      newf = best_nearby ( delta, newx, fbefore, nvars, f, &funevals );

      if ( fbefore <= newf )
      {
        break;
      }

      keep = 0;

      for ( i = 0; i < nvars; i++ )
      {
        if ( 0.5 * r8_abs ( delta[i] ) < r8_abs ( newx[i] - xbefore[i] ) )
        {
          keep = 1;
          break;
        }
      }
    }

    if ( eps <= steplength && fbefore <= newf )
    {
      steplength = steplength * rho;
      for ( i = 0; i < nvars; i++ )
      {
        delta[i] = delta[i] * rho;
      }
    }

  }

  for ( i = 0; i < nvars; i++ )
  {
    endpt[i] = xbefore[i];
  }

  delete [] delta;
  delete [] newx;
  delete [] xbefore;

  return iters;
}

double r8_abs ( double x )
{
  double value;

  if ( 0.0 <= x )
  {
    value = x;
  } 
  else
  {
    value = -x;
  }
  return value;
}
