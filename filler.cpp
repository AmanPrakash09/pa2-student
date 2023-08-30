/**
 * File:        filler.cpp
 * Description: Implementation of functions in the filler namespace.
 *
 *              SUBMIT THIS FILE WITH YOUR MODIFICATIONS
 */

/**
 * Performs a flood fill using breadth first search.
 *
 * @param config FillerConfig struct to setup the fill
 * @return animation object illustrating progression of flood fill algorithm
 */
animation filler::FillBFS(FillerConfig& config) {
	// complete your implementation below
	// You should replace the following line with a
	// correct call to fill.
	// return animation(); // REPLACE THIS STUB
	return Fill<Queue>(config);
}

/**
 * Performs a flood fill using depth first search.
 *
 * @param  config - FillerConfig struct to setup the fill
 * @return animation object illustrating progression of flood fill algorithm
 */
animation filler::FillDFS(FillerConfig& config) {
	// complete your implementation below
	// You should replace the following line with a
	// correct call to fill.
	// return animation(); // REPLACE THIS STUB
	return Fill<Stack>(config);
}

/**
 * Run a flood fill on an image starting at the seed point
 *
 * @param config FillerConfig struct with data for flood fill of image
 * @return animation object illustrating progression of flood fill algorithm
 */
template <template <class T> class OrderingStructure> animation filler::Fill(FillerConfig& config)
{
	/**
	 * You need to implement this function!
	 *
	 * This is the basic description of a flood-fill algorithm: Every fill
	 * algorithm requires an ordering structure, which is passed to this
	 * function via its template parameter. For a breadth-first-search
	 * fill, that structure is a Queue, for a depth-first-search, that
	 * structure is a Stack. To begin the algorithm, you simply place the
	 * given point in the ordering structure, marking it processed
	 * (the way you mark it is a design decision you'll make yourself).
	 * We have a choice to either change the color, if appropriate, when we
	 * add the point to the OS, or when we take it off. In our test cases,
	 * we have assumed that you will change the color when a point is removed
	 * from the structure.
	 * Until the structure is empty, you do the following:
	 *
	 * 1.     Remove a point from the ordering structure, and then...
	 *
	 *        1.    add its unprocessed neighbors (up/down/left/right) whose color values are
	 *              within (or equal to) tolerance distance from the seed point,
	 *              to the ordering structure, and
	 *              mark them as processed.
	 *        2.    if it is an appropriate frame, send the current PNG to the
	 *              animation (as described below).
	 *
	 * 2.     When implementing your breadth-first-search and
	 *        depth-first-search fills, you will need to explore neighboring
	 *        pixels (up/down/left/right) in some order.
	 *
	 *        While the order in which you examine neighbors does not matter
	 *        for a proper fill, you must use the same order as we do for
	 *        your animations to come out like ours! The order you should put
	 *        neighboring pixels **ONTO** the queue or stack is as follows:
	 *        1. western neighbour (left)
	 *        2. northern neighbour (up)
	 *        3. eastern neighbour (right)
	 *        4. southern neighbour (down)
	 * 
	 *        If you process the neighbours in a different order, your fill may
	 *        still work correctly, but your animations will be different
	 *        from the grading scripts!
	 *
	 * 3.     For every k pixels filled, **starting at the kth pixel**, you
	 *        must add a frame to the animation, where k = frameFreq.
	 *
	 *        For example, if frameFreq is 4, then after the 4th pixel has
	 *        been filled you should add a frame to the animation, then again
	 *        after the 8th pixel, etc.  You must only add frames for the
	 *        number of pixels that have been filled, not the number that
	 *        have been checked. So if frameFreq is set to 1, a pixel should
	 *        be filled every frame.
	 *
	 * 4.     Finally, as you leave the function, send one last frame to the
	 *        animation. This frame will be the final result of the fill, and
	 *        it will be the one we test against.
	 *
	 */

	int framecount = 0; // increment after processing one pixel; used for producing animation frames (step 3 above)
	animation anim;
	OrderingStructure<PixelPoint> os;

	// complete your implementation below
	// HINT: you will likely want to declare some kind of structure to track
	//       which pixels have already been visited

    vector<vector<bool>> visited(config.img.width(), vector<bool>(config.img.height(), false));

    PixelPoint seedPoint = config.seedpoint;
    os.Add(seedPoint);
    visited[seedPoint.x][seedPoint.y] = true;

    while (!os.IsEmpty()) {
        PixelPoint current = os.Remove();

		HSLAPixel* pixel = config.img.getPixel(current.x, current.y);
        *pixel = config.picker->operator()(current);

        framecount++;

		if (framecount % config.frameFreq == 0) {
			anim.addFrame(config.img);
		}

		for (int i = 0; i < 4; i++) {
			unsigned int neighborX = 0;
			unsigned int neighborY = 0;
			if (i == 0) {
				neighborX = current.x - 1;
				neighborY = current.y;
			}
			else if (i == 1) {
				neighborX = current.x;
				neighborY = current.y - 1;
			}
			else if (i == 2) {
				neighborX = current.x + 1;
				neighborY = current.y;
			}
			else {
				neighborX = current.x;
				neighborY = current.y + 1;
			}

            if (neighborX >= config.img.width() || neighborY >= config.img.height()) {
                continue;
			}

			// double distance = config.img.getPixel(current.x, current.y)->distanceTo(*config.img.getPixel(neighborX, neighborY));
			double distance = config.seedpoint.color.distanceTo(*config.img.getPixel(neighborX, neighborY));

			// std::cout << distance << "," << config.tolerance << endl;

            if (!visited[neighborX][neighborY] && distance <= config.tolerance) {
                visited[neighborX][neighborY] = true;
                os.Add(PixelPoint(neighborX, neighborY));
            }
        }
    }

    anim.addFrame(config.img);

	return anim;
}
