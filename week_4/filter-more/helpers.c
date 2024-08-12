#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE grayscale = (BYTE)round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtRed = grayscale;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int mid = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            RGBTRIPLE tmpt = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmpt;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a tempture 2-D array to store the pixel information
    RGBTRIPLE tmpts[height][width];

    for (int i = 0; i <height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate the average for every pixel
            int red = 0, blue = 0, green = 0, count = 0;
            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    if (i + m > -1 && i + m < height && j + n > -1 && j + n < width)
                    {
                        red += image[i + m][j + n].rgbtRed;
                        blue += image[i + m][j + n].rgbtBlue;
                        green += image[i + m][j + n].rgbtGreen;
                        count++;
                    }
                }
            }

            tmpts[i][j].rgbtRed = (BYTE)round(red / (float)count);
            tmpts[i][j].rgbtBlue = (BYTE)round(blue / (float)count);
            tmpts[i][j].rgbtGreen = (BYTE)round(green / (float)count);
        }
    }

    //assign all the value of tmpt into image
    for (int i = 0; i <height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmpts[i][j];
        }
    }
    return;
}

// Detect edges
int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmpts[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // add all number to the tmpt variable
            int tmpt_x_red = 0, tmpt_x_blue = 0, tmpt_x_green = 0, tmpt_y_red = 0, tmpt_y_blue = 0, tmpt_y_green = 0;
            for (int m = 0; m < 3; m++)
            {

                for (int n = 0; n < 3; n++)
                {
                    if (i + m - 1 > -1 && i + m - 1 < height && j + n - 1 > -1 && j + n - 1 < width)
                    {
                        // accumulate the Gx
                        tmpt_x_red += image[i + m - 1][j + n - 1].rgbtRed * Gx[m][n];
                        tmpt_x_blue += image[i + m - 1][j + n - 1].rgbtBlue * Gx[m][n];
                        tmpt_x_green += image[i + m - 1][j + n - 1].rgbtGreen * Gx[m][n];
                        // accumulate the Gy
                        tmpt_y_red += image[i + m - 1][j + n - 1].rgbtRed * Gy[m][n];
                        tmpt_y_blue += image[i + m - 1][j + n - 1].rgbtBlue * Gy[m][n];
                        tmpt_y_green += image[i + m - 1][j + n - 1].rgbtGreen * Gy[m][n];
                    }
                }
            }
            double red = round(sqrt(pow(tmpt_x_red, 2) + pow(tmpt_y_red, 2)));
            double blue = round(sqrt(pow(tmpt_x_blue, 2) + pow(tmpt_y_blue, 2)));
            double green = round(sqrt(pow(tmpt_x_green, 2) + pow(tmpt_y_green, 2)));

            tmpts[i][j].rgbtRed = (red > 255)? 255 : (BYTE)red;
            tmpts[i][j].rgbtBlue = (blue > 255)? 255 : (BYTE)blue;
            tmpts[i][j].rgbtGreen = (green > 255)? 255 : (BYTE)green;
        }
    }

    //assign all the value of tmpt into image
    for (int i = 0; i <height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmpts[i][j];
        }
    }
    return;
}
