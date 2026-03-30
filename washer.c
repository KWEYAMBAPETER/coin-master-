/*
 * Computes the weight of a batch of flat washers
 */

#include <stdio.h>

#define PI 3.14159

/* Function prototypes */
double find_area(double r);
double find_rim_area(double hole_radius, double edge_radius);

int
main(void)
{
  double hole_diameter, edge_diameter, thickness, density, quantity;
  double weight, hole_radius, edge_radius, rim_area, unit_weight;

  /* Get the inner diameter, outer diameter, and thickness */
  printf("Inner diameter in centimeters> ");
  scanf("%lf", &hole_diameter);
  printf("Outer diameter in centimeters> ");
  scanf("%lf", &edge_diameter);
  printf("Thickness in centimeters> ");
  scanf("%lf", &thickness);

  /* Get the material density and quantity manufactured */
  printf("Material density in grams per cubic centimeter> ");
  scanf("%lf", &density);
  printf("Quantity in batch> ");
  scanf("%lf", &quantity);

  /* Compute the rim area */
  hole_radius = hole_diameter / 2.0;
  edge_radius = edge_diameter / 2.0;
  rim_area = find_rim_area(hole_radius, edge_radius);

  /* Compute the weight of a flat washer */
  unit_weight = rim_area * thickness * density;

  /* Compute the weight of the batch of washers */
  weight = unit_weight * quantity;

  /* Display the weight of the batch of washers */
  printf("\nThe expected weight of the batch is %.2f grams.\n", weight);

  return (0);
}

/*
 * Computes the area of a circle with radius r
 * Pre: r is defined and is >= 0
 */
double
find_area(double r)
{
  return (PI * r * r);
}

/*
 * Computes the rim area of a washer
 * Pre: hole_radius and edge_radius are defined and >= 0
 */
double
find_rim_area(double hole_radius, double edge_radius)
{
  return (find_area(edge_radius) - find_area(hole_radius));
}